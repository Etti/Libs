object fMain: TfMain
  Left = 0
  Top = 0
  Caption = 'LibReader'
  ClientHeight = 462
  ClientWidth = 384
  Color = clBtnFace
  Constraints.MinHeight = 500
  Constraints.MinWidth = 400
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pcMenuPages: TPageControl
    Left = 0
    Top = 0
    Width = 384
    Height = 462
    ActivePage = tsLib
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    HotTrack = True
    ParentFont = False
    TabHeight = 30
    TabOrder = 0
    OnMouseUp = pcMenuPagesMouseUp
    object tsReading: TTabSheet
      Caption = #1063#1090#1077#1085#1080#1077
      TabVisible = False
      DesignSize = (
        376
        422)
      object sbBookmark: TSpeedButton
        Left = 341
        Top = 0
        Width = 32
        Height = 32
        Hint = #1055#1086#1089#1090#1072#1074#1080#1090#1100' '#1079#1072#1082#1083#1072#1076#1082#1091
        Anchors = [akTop, akRight]
        ParentShowHint = False
        ShowHint = True
        OnClick = sbBookmarkClick
      end
      object lbBookName: TLabel
        Left = 3
        Top = 3
        Width = 332
        Height = 29
        AutoSize = False
        Caption = #1053#1077#1090' '#1082#1085#1080#1075#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        Layout = tlCenter
      end
      object mBook: TMemo
        Left = 3
        Top = 38
        Width = 370
        Height = 381
        Anchors = [akLeft, akTop, akRight, akBottom]
        BorderStyle = bsNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          #1053#1077#1090' '#1082#1085#1080#1075#1080)
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object tsLib: TTabSheet
      Caption = #1052#1086#1080' '#1050#1085#1080#1075#1080
      ImageIndex = 1
      DesignSize = (
        376
        422)
      object sbOpenBook: TSpeedButton
        Left = 3
        Top = 0
        Width = 32
        Height = 32
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1082#1085#1080#1075#1091
        ParentShowHint = False
        ShowHint = True
        OnClick = sbOpenBookClick
      end
      object sbDeleteBook: TSpeedButton
        Left = 36
        Top = 0
        Width = 32
        Height = 32
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1082#1085#1080#1075#1091
        ParentShowHint = False
        ShowHint = True
        OnClick = sbDeleteBookClick
      end
      object lvLib: TListView
        Left = 3
        Top = 38
        Width = 370
        Height = 387
        Anchors = [akLeft, akTop, akRight, akBottom]
        BorderStyle = bsNone
        Columns = <
          item
            AutoSize = True
            Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1082#1085#1080#1075#1080
            MinWidth = 350
          end>
        Groups = <
          item
            Header = #1051#1086#1082#1072#1083#1100#1085#1072#1103' '#1073#1080#1073#1083#1080#1086#1090#1077#1082#1072
            GroupID = 0
            State = [lgsNormal, lgsCollapsible]
            HeaderAlign = taCenter
            FooterAlign = taLeftJustify
            Subtitle = #1057#1087#1080#1089#1086#1082' '#1082#1085#1080#1075
            TitleImage = -1
            ExtendedImage = -1
          end>
        HotTrack = True
        GroupView = True
        ReadOnly = True
        ParentShowHint = False
        ShowColumnHeaders = False
        ShowHint = False
        SortType = stText
        TabOrder = 0
        ViewStyle = vsReport
        OnDblClick = lvLibDblClick
      end
    end
    object tsWeb: TTabSheet
      Caption = #1041#1080#1073#1083#1080#1086#1090#1077#1082#1072
      ImageIndex = 2
      object wbLibs: TWebBrowser
        Left = 0
        Top = 0
        Width = 376
        Height = 422
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 128
        ExplicitTop = 120
        ExplicitWidth = 300
        ExplicitHeight = 150
        ControlData = {
          4C000000DC2600009D2B00000000000000000000000000000000000000000000
          000000004C000000000000000000000001000000E0D057007335CF11AE690800
          2B2E126208000000000000004C0000000114020000000000C000000000000046
          8000000000000000000000000000000000000000000000000000000000000000
          00000000000000000100000000000000000000000000000000000000}
      end
    end
    object tsSettings: TTabSheet
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      ImageIndex = 3
    end
  end
  object IdHTTP1: TIdHTTP
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.Accept = 'text/html, */*'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    HTTPOptions = [hoForceEncodeParams]
    Left = 328
    Top = 416
  end
  object odOpenBook: TOpenTextFileDialog
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1077' '#1092#1072#1081#1083#1099' (*.txt)|*.txt|'#1042#1089#1077' '#1092#1072#1081#1083#1099' (*.*)|*.*'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Title = #1054#1090#1082#1088#1099#1090#1100' '#1082#1085#1080#1075#1091
    OnCanClose = odOpenBookCanClose
    Left = 264
    Top = 416
  end
end
