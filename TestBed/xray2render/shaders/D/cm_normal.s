struct 	a2v
{
  float4 Position: 	POSITION;	// Object-space position
  float2 tc0: 		TEXCOORD0;	// Texture coordinates
};

struct 	v2p_out
{
  float4 HPos: 		POSITION;	// Clip-space position 	(for rasterization)
  float2 tc0: 		TEXCOORD0;	// Texture coordinates 	(for sampling maps)
};

struct 	v2p_in
{
  half2 tc0: 		TEXCOORD0;	// Texture coordinates 	(for sampling maps)
};

struct 	p2f
{
  half4 C:			COLOR0;		// Final color
};

//////////////////////////////////////////////////////////////////////////////////////////
uniform sampler2D 	s_position;
uniform sampler2D 	s_normal;
uniform sampler2D 	s_diffuse;
uniform sampler2D 	s_accumulator;
uniform sampler2D	s_bloom;

//////////////////////////////////////////////////////////////////////////////////////////
// Vertex
v2p_out v_main	( a2v  	IN )
{
  v2p_out 	OUT;
  OUT.HPos 	= IN.Position;				// pass-through
  OUT.tc0 	= IN.tc0;
  return	OUT;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Pixel
p2f 	p_main	( v2p_in IN )
{
  p2f		OUT;

  half4 D	= tex2D		(s_diffuse,		IN.tc0);	// rgb.gloss
  half4 L 	= tex2D		(s_accumulator, IN.tc0);	// diffuse.specular
  half4 B	= tex2D		(s_bloom,		IN.tc0);	// diffuse glow / specular bloom
  
  half4 C	= D*L;									// rgb.gloss * light(diffuse.specular)
  half4 S	= half4		(C.w,C.w,C.w,C.w);			// replicated specular
  OUT.C 	= C + S + B;							// sum everything
  return OUT;
}
