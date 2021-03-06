//----------------------------------------------------
// file: SceneClassList.cpp
//----------------------------------------------------
#include "stdafx.h"
#pragma hdrstop

#include "SceneClassList.h"
#include "Scene.h"
#include "ui_tools.h"
#include "SceneObject.h"
#include "ELight.h"
#include "Sound.h"
#include "glow.h"
#include "rpoint.h"
#include "WayPoint.h"
#include "sector.h"
#include "portal.h"
#include "event.h"
#include "PSObject.h"
#include "DetailObjects.h"
#include "GroupObject.h"
//----------------------------------------------------

CCustomObject *NewObjectFromClassID( int _ClassID ){
	switch( _ClassID ){
    	case OBJCLASS_GROUP:	return new CGroupObject();
		case OBJCLASS_SCENEOBJECT: return new CSceneObject();
		case OBJCLASS_LIGHT:    return new CLight();
		case OBJCLASS_SOUND:    return new CSound();
		case OBJCLASS_GLOW:     return new CGlow();
        case OBJCLASS_RPOINT:   return new CRPoint();
        case OBJCLASS_WAY:		return new CWayObject();
        case OBJCLASS_SECTOR:	return new CSector();
        case OBJCLASS_PORTAL:	return new CPortal();
        case OBJCLASS_EVENT:	return new CEvent();
        case OBJCLASS_PS:		return new CPSObject();
        default: throw -1;
	}
}
//----------------------------------------------------
LPSTR GetNameByClassID(EObjClass cls_id){
    switch(cls_id){
	case OBJCLASS_GROUP:	return "group";
    case OBJCLASS_SCENEOBJECT: return "object";
    case OBJCLASS_LIGHT:    return "light";
    case OBJCLASS_SOUND:    return "sound";
    case OBJCLASS_GLOW:     return "glow";
    case OBJCLASS_RPOINT:   return "rpoint";
    case OBJCLASS_WAY:		return "way";
    case OBJCLASS_SECTOR: 	return "sector";
    case OBJCLASS_PORTAL: 	return "portal";
    case OBJCLASS_EVENT: 	return "event";
    case OBJCLASS_PS:		return "ps";
    case OBJCLASS_DO:		return "detailobject";
    default: THROW2("Gen empty name"); return 0;
    }
}
bool IsClassID(EObjClass cls_id){
    switch(cls_id){
	case OBJCLASS_GROUP:	return true;
    case OBJCLASS_SCENEOBJECT: return true;
    case OBJCLASS_LIGHT:    return true;
    case OBJCLASS_SOUND:    return true;
    case OBJCLASS_GLOW:     return true;
    case OBJCLASS_RPOINT:   return true;
    case OBJCLASS_WAY:		return true;
    case OBJCLASS_SECTOR: 	return true;
    case OBJCLASS_PORTAL: 	return true;
    case OBJCLASS_EVENT: 	return true;
    case OBJCLASS_PS:		return true;
    case OBJCLASS_DO:		return true;
    default: return 0;
    }
}
EObjClass ClassIDFromTargetID( int cls_id ){
	switch( cls_id ){
	case etGroup:	return OBJCLASS_GROUP;
	case etObject:  return OBJCLASS_SCENEOBJECT;
	case etSound:   return OBJCLASS_SOUND;
	case etLight:   return OBJCLASS_LIGHT;
	case etGlow:    return OBJCLASS_GLOW;
	case etRPoint:  return OBJCLASS_RPOINT;
	case etWay:		return OBJCLASS_WAY;
    case etSector:	return OBJCLASS_SECTOR;
    case etPortal:	return OBJCLASS_PORTAL;
    case etEvent:	return OBJCLASS_EVENT;
    case etPS:		return OBJCLASS_PS;
	case etDO: 		return OBJCLASS_DO;
    default: throw -1;
	}
}
bool IsObjectListClassID(EObjClass cls_id){
    switch(cls_id){
	case OBJCLASS_GROUP:	return true;
    case OBJCLASS_SCENEOBJECT: return true;
    case OBJCLASS_LIGHT:    return true;
    case OBJCLASS_SOUND:    return true;
    case OBJCLASS_GLOW:     return true;
    case OBJCLASS_RPOINT:   return true;
    case OBJCLASS_WAY:		return true;
    case OBJCLASS_SECTOR:	return true;
    case OBJCLASS_PORTAL:	return true;
    case OBJCLASS_EVENT:	return true;
    case OBJCLASS_PS:		return true;
    case OBJCLASS_DO:		return true;
    default: return false;
    }
}
bool IsGroupClassID(EObjClass cls_id)
{
    switch(cls_id){
    case OBJCLASS_SCENEOBJECT: return true;
    case OBJCLASS_LIGHT:    return true;
    case OBJCLASS_SOUND:    return true;
    case OBJCLASS_GLOW:     return true;
    case OBJCLASS_RPOINT:   return true;
    case OBJCLASS_EVENT:	return true;
    case OBJCLASS_PS:		return true;
    default: return false;
    }
}

