object fraBottomBar: TfraBottomBar
  Left = 0
  Top = 0
  Width = 786
  Height = 277
  VertScrollBar.Visible = False
  Align = alClient
  TabOrder = 0
  object paBottomBar: TPanel
    Left = 0
    Top = 0
    Width = 786
    Height = 17
    Align = alTop
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 0
    object paInfo: TPanel
      Left = 74
      Top = 1
      Width = 653
      Height = 15
      Align = alClient
      Alignment = taLeftJustify
      BevelOuter = bvNone
      TabOrder = 0
      object paStatus: TPanel
        Left = 150
        Top = 0
        Width = 221
        Height = 15
        Align = alClient
        Alignment = taLeftJustify
        BevelInner = bvLowered
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clMaroon
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object cgProgress: TCGauge
          Left = 92
          Top = 2
          Width = 127
          Height = 11
          Align = alRight
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clMaroon
          Font.Height = -11
          Font.Name = 'MS Serif'
          Font.Style = []
          ForeColor = 5592405
          ParentFont = False
          Progress = 75
          Visible = False
        end
      end
      object paStatusLabel: TPanel
        Left = 102
        Top = 0
        Width = 48
        Height = 15
        Align = alLeft
        BevelInner = bvRaised
        BevelOuter = bvNone
        Caption = 'Status:'
        TabOrder = 1
      end
      object paCameraPos: TPanel
        Left = 429
        Top = 0
        Width = 130
        Height = 15
        Align = alRight
        Alignment = taLeftJustify
        BevelInner = bvLowered
        Caption = 'Cam: (123,123,123)'
        Color = clSilver
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object paButtons: TPanel
        Left = 0
        Top = 0
        Width = 102
        Height = 15
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 3
        object ebLog: TExtBtn
          Left = 0
          Top = 0
          Width = 34
          Height = 15
          Align = alNone
          BevelShow = False
          CloseButton = False
          Caption = 'Log'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          Kind = knMinimize
          ParentFont = False
          Spacing = 0
          Transparent = False
          FlatAlwaysEdge = True
          OnClick = ebLogClick
        end
        object ebStop: TExtBtn
          Left = 68
          Top = 0
          Width = 34
          Height = 15
          Align = alNone
          BevelShow = False
          CloseButton = False
          Caption = 'Break'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          Kind = knMinimize
          ParentFont = False
          Transparent = False
          FlatAlwaysEdge = True
          OnClick = ebStopClick
        end
        object ebStat: TExtBtn
          Left = 34
          Top = 0
          Width = 34
          Height = 15
          Align = alNone
          AllowAllUp = True
          BevelShow = False
          CloseButton = False
          GroupIndex = 1
          Caption = 'Stat'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          Kind = knMinimize
          ParentFont = False
          Spacing = 0
          Transparent = False
          FlatAlwaysEdge = True
          OnClick = ebStatClick
        end
      end
      object paSel: TPanel
        Left = 371
        Top = 0
        Width = 58
        Height = 15
        Align = alRight
        Alignment = taLeftJustify
        BevelInner = bvLowered
        Caption = 'Sel: 1024'
        Color = clSilver
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
      object paUICursor: TPanel
        Left = 559
        Top = 0
        Width = 94
        Height = 15
        Align = alRight
        Alignment = taLeftJustify
        BevelInner = bvLowered
        Caption = 'Cursor:1025, 2048'
        Color = clSilver
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
      end
    end
    object paMenu: TPanel
      Left = 1
      Top = 1
      Width = 73
      Height = 15
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 1
      object ebOptions: TExtBtn
        Left = 0
        Top = 0
        Width = 73
        Height = 15
        Align = alNone
        BevelShow = False
        Caption = 'Options'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Kind = knMinimize
        ParentFont = False
        Transparent = False
        FlatAlwaysEdge = True
        OnMouseDown = ebOptionsMouseDown
      end
    end
    object paGridSquareSize: TPanel
      Left = 727
      Top = 1
      Width = 58
      Height = 15
      Align = alRight
      Alignment = taLeftJustify
      BevelInner = bvLowered
      Caption = 'Grid: 0.1 m'
      Color = clSilver
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object fsStorage: TFormStorage
    IniSection = 'Bottom Bar'
    Options = [fpState]
    RegistryRoot = prLocalMachine
    OnRestorePlacement = fsStorageRestorePlacement
    StoredProps.Strings = (
      'miDrawGrid.Checked'
      'miDrawPortalSimpleModel.Checked'
      'miDrawSectors.Checked'
      'N100.Checked'
      'N125.Checked'
      'N150.Checked'
      'N200.Checked'
      'N25.Checked'
      'N50.Checked'
      'N75.Checked'
      'miDrawAnimateLight.Checked'
      'miDrawObjectBones.Checked'
      'miObjectLoopedAnimation.Checked'
      'miDrawSky.Checked'
      'miDrawObjectAnimPath.Checked'
      'ebStat.Down'
      'miFog.Checked'
      'miLightScene.Checked'
      'miRealTime.Checked'
      'miRenderEdgedFaces.Checked'
      'miRenderFillPoint.Checked'
      'miRenderFillSolid.Checked'
      'miRenderFillWireframe.Checked'
      'miRenderHWTransform.Checked'
      'miRenderLinearFilter.Checked'
      'miRenderShadeFlat.Checked'
      'miRenderShadeGouraud.Checked'
      'miRenderWithTextures.Checked'
      'miDrawSectorSolid.Checked'
      'miShowHint.Checked'
      'miDrawDOSlotBoxes.Checked'
      'miDODrawObjects.Checked'
      'miGlowTestVisibility.Checked'
      'miDrawObjectsPivot.Checked'
      'miDrawDOBaseTexture.Checked'
      'miDrawDOBlended.Checked')
    StoredValues = <>
    Left = 185
    Top = 33
  end
  object pmOptions: TMxPopupMenu
    Alignment = paCenter
    AutoPopup = False
    TrackButton = tbLeftButton
    MarginStartColor = 10921638
    MarginEndColor = 2763306
    BKColor = 10528425
    SelColor = clBlack
    SelFontColor = 10526880
    SepHColor = 1644825
    SepLColor = 13158600
    LeftMargin = 10
    Style = msOwnerDraw
    Left = 5
    Top = 24
    object Render1: TMenuItem
      Caption = 'Render'
      object Quality1: TMenuItem
        Caption = 'Quality'
        object N25: TMenuItem
          Tag = 25
          Caption = '25%'
          RadioItem = True
          OnClick = QualityClick
        end
        object N50: TMenuItem
          Tag = 50
          Caption = '50%'
          RadioItem = True
          OnClick = QualityClick
        end
        object N75: TMenuItem
          Tag = 75
          Caption = '75%'
          RadioItem = True
          OnClick = QualityClick
        end
        object N100: TMenuItem
          Tag = 100
          Caption = '100%'
          Checked = True
          RadioItem = True
          OnClick = QualityClick
        end
        object N125: TMenuItem
          Tag = 125
          Caption = '125%'
          RadioItem = True
          OnClick = QualityClick
        end
        object N150: TMenuItem
          Tag = 150
          Caption = '150%'
          RadioItem = True
          OnClick = QualityClick
        end
        object N200: TMenuItem
          Tag = 200
          Caption = '200%'
          RadioItem = True
          OnClick = QualityClick
        end
      end
      object FillMode1: TMenuItem
        Caption = 'Fill Mode'
        object miRenderFillPoint: TMenuItem
          Caption = 'Point'
          RadioItem = True
          OnClick = ClickOptionsMenuItem
        end
        object miRenderFillWireframe: TMenuItem
          Caption = 'Wireframe'
          RadioItem = True
          OnClick = ClickOptionsMenuItem
        end
        object miRenderFillSolid: TMenuItem
          Caption = 'Solid'
          Checked = True
          RadioItem = True
          OnClick = ClickOptionsMenuItem
        end
      end
      object ShadeMode1: TMenuItem
        Caption = 'Shade Mode'
        object miRenderShadeFlat: TMenuItem
          Caption = 'Flat'
          Checked = True
          RadioItem = True
          OnClick = ClickOptionsMenuItem
        end
        object miRenderShadeGouraud: TMenuItem
          Caption = 'Gouraud'
          RadioItem = True
          OnClick = ClickOptionsMenuItem
        end
      end
      object miRenderEdgedFaces: TMenuItem
        Caption = 'Edged Faces'
        GroupIndex = 4
        OnClick = ClickOptionsMenuItem
      end
      object N7: TMenuItem
        Caption = '-'
        GroupIndex = 4
      end
      object miRenderHWTransform: TMenuItem
        Caption = 'Limit to 8 Lights'
        Checked = True
        GroupIndex = 4
        OnClick = ClickOptionsMenuItem
      end
      object N8: TMenuItem
        Caption = '-'
        GroupIndex = 4
      end
      object miRenderLinearFilter: TMenuItem
        Caption = 'Linear Filter'
        Checked = True
        GroupIndex = 4
        OnClick = ClickOptionsMenuItem
      end
      object miRenderWithTextures: TMenuItem
        Caption = 'Textures'
        Checked = True
        GroupIndex = 4
        OnClick = ClickOptionsMenuItem
      end
    end
    object N2: TMenuItem
      Caption = '-'
      GroupIndex = 4
    end
    object Objects1: TMenuItem
      Caption = 'Objects'
      GroupIndex = 4
      object miDrawObjectBones: TMenuItem
        Caption = 'Draw Bones'
        OnClick = ClickOptionsMenuItem
      end
      object miObjectLoopedAnimation: TMenuItem
        Caption = 'Looped Animation'
        OnClick = ClickOptionsMenuItem
      end
      object miDrawObjectAnimPath: TMenuItem
        Caption = 'Draw Animation Path'
        Checked = True
        OnClick = ClickOptionsMenuItem
      end
    end
    object miDrawSectors: TMenuItem
      Caption = 'Sectors'
      GroupIndex = 4
      object miDrawSectorSolid: TMenuItem
        Caption = 'Draw Solid'
        Checked = True
        GroupIndex = 1
        OnClick = ClickOptionsMenuItem
      end
    end
    object Portals1: TMenuItem
      Caption = 'Portals'
      GroupIndex = 4
      object miDrawPortalSimpleModel: TMenuItem
        Caption = 'Draw Simple Model'
        OnClick = ClickOptionsMenuItem
      end
    end
    object Animations1: TMenuItem
      Caption = 'Light'
      GroupIndex = 4
      object miDrawAnimateLight: TMenuItem
        Caption = 'Animate'
        OnClick = ClickOptionsMenuItem
      end
    end
    object DetailObjects1: TMenuItem
      Caption = 'Detail Objects'
      GroupIndex = 4
      object miDOBase: TMenuItem
        Caption = 'Base Texture'
        object miDrawDOBaseTexture: TMenuItem
          Caption = 'Draw'
          OnClick = ClickOptionsMenuItem
        end
        object miDrawDOBlended: TMenuItem
          Caption = 'Blended'
          OnClick = ClickOptionsMenuItem
        end
      end
      object miDrawDOSlotBoxes: TMenuItem
        Caption = 'Draw Slot Boxes'
        OnClick = ClickOptionsMenuItem
      end
      object miDODrawObjects: TMenuItem
        Caption = 'Draw Objects'
        Checked = True
        OnClick = ClickOptionsMenuItem
      end
    end
    object Glow1: TMenuItem
      Caption = 'Glow'
      GroupIndex = 4
      object miGlowTestVisibility: TMenuItem
        Caption = 'Test Visibility'
        OnClick = ClickOptionsMenuItem
      end
    end
    object miDrawObjectsPivot: TMenuItem
      Caption = 'Draw Objects Pivot'
      Checked = True
      GroupIndex = 4
      OnClick = ClickOptionsMenuItem
    end
    object N4: TMenuItem
      Caption = '-'
      GroupIndex = 4
    end
    object miDrawGrid: TMenuItem
      Caption = 'Draw Grid'
      Checked = True
      GroupIndex = 4
      OnClick = ClickOptionsMenuItem
    end
    object miDrawSky: TMenuItem
      Caption = 'Draw Sky'
      Checked = True
      GroupIndex = 4
      OnClick = ClickOptionsMenuItem
    end
    object N3: TMenuItem
      Caption = '-'
      GroupIndex = 4
    end
    object miShowHint: TMenuItem
      Caption = 'Show Hint'
      GroupIndex = 4
      OnClick = ClickOptionsMenuItem
    end
    object N1: TMenuItem
      Caption = '-'
      GroupIndex = 4
    end
    object miLightScene: TMenuItem
      Caption = 'Light Scene'
      Checked = True
      GroupIndex = 4
      OnClick = ClickOptionsMenuItem
    end
    object miFog: TMenuItem
      Caption = 'Fog'
      Checked = True
      GroupIndex = 4
      OnClick = ClickOptionsMenuItem
    end
    object miRealTime: TMenuItem
      Caption = 'Real Time'
      GroupIndex = 4
      OnClick = ClickOptionsMenuItem
    end
  end
end
