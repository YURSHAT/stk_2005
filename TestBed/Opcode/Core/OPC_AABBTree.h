///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	OPCODE - Optimized Collision Detection
 *	Copyright (C) 2001 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Opcode.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for a versatile AABB tree.
 *	\file		OPC_AABBTree.h
 *	\author		Pierre Terdiman
 *	\date		March, 20, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef __OPC_AABBTREES_H__
#define __OPC_AABBTREES_H__

	//! TO BE DOCUMENTED
	#define IMPLEMENT_TREE(baseclass, volume)																					\
		public:																													\
		/* Constructor / Destructor */																							\
											baseclass();																		\
											~baseclass();																		\
		/* Data access */																										\
		__forceinline	const volume*		Get##volume()	const	{ return &mBV;			}									\
		__forceinline	const baseclass*	GetPos()		const	{ return mP;			}									\
		__forceinline	const baseclass*	GetNeg()		const	{ return mN;			}									\
																																\
		__forceinline	bool				IsLeaf()		const	{ return (!mP && !mN);	}									\
																																\
		/* Stats */																												\
		__forceinline	udword				GetNodeSize()	const	{ return SIZEOFOBJECT;	}									\
		protected:																												\
		/* Tree-independent data */																								\
		/* Following data always belong to the BV-tree, regardless of what the tree actually contains.*/						\
		/* Whatever happens we need the two children and the enclosing volume.*/												\
						volume				mBV;		/* Global bounding-volume enclosing all the node-related primitives */	\
						baseclass*			mP;																					\
						baseclass*			mN;

	class OPCODE_API AABBTreeNode
	{
											IMPLEMENT_TREE(AABBTreeNode, AABB)
		public:
		// Data access
		__forceinline	const udword*		GetPrimitives()		const	{ return mNodePrimitives;	}
		__forceinline	udword				GetNbPrimitives()	const	{ return mNbPrimitives;		}

		protected:
		// Tree-dependent data
						udword*				mNodePrimitives;	//!< Node-related primitives (shortcut to a position in mIndices below)
						udword				mNbPrimitives;		//!< Number of primitives for this node
		// Internal methods
						udword				Split(udword axis, AABBTreeBuilder* builder);
						bool				Subdivide(AABBTreeBuilder* builder);
						void				_BuildHierarchy(AABBTreeBuilder* builder);
	};

	class OPCODE_API AABBTree : public AABBTreeNode
	{
		public:
		// Constructor / Destructor
											AABBTree();
											~AABBTree();
		// Build
						bool				Build(AABBTreeBuilder* builder);
		// Data access
		__forceinline	const udword*		GetIndices()		const	{ return mIndices;		}	//!< Catch the indices
		__forceinline	udword				GetNbNodes()		const	{ return mTotalNbNodes;	}	//!< Catch the number of nodes

		// Infos
						bool				IsComplete()		const;
		// Stats
						udword				ComputeDepth()		const;
						udword				GetUsedBytes()		const;
		private:
						udword*				mIndices;			//!< Indices in the app list. Indices are reorganized during build.
		// Stats
						udword				mTotalNbNodes;		//!< Number of nodes in the tree.
	};

#endif // __OPC_AABBTREES_H__
