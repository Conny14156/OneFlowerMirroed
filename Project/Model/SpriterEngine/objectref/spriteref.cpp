#include "spriteref.h"

#include "../entity/entityinstance.h"

#include "spriterefinstance.h"
#include "..\..\..\AssetManager\SpriteRef.hpp"

namespace SpriterEngine
{
	SpriteRef::SpriteRef(s_int initialObjectId, s_int initialParentObjectId, TimelineKey *initialKey, s_int initialFileId, bool initialUseDefaultPivot) :
		ObjectRef(initialObjectId, initialParentObjectId, initialKey),
		fileId(initialFileId),
		useDefaultPivot(initialUseDefaultPivot)
	{
	}

	ObjectRefInstance *SpriteRef::getNewSpecializedObjectRefInstance(EntityInstance *entityInstance, EntityInstanceData *entityInstanceData, TransformProcessor *initialParentTransformer, UniversalObjectInterface *objectInstance)
	{
		return new SpriteRefInstance(objectInstance, initialParentTransformer, getKey(), entityInstance->getFile(fileId), useDefaultPivot);
	}
}
