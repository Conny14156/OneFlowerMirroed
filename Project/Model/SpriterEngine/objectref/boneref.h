#ifndef BONEREF_H
#define BONEREF_H

#include "objectref.h"

namespace SpriterEngine
{
	class TransformProcessor;

	class BoneRef : public ObjectRef
	{
	public:
		BoneRef(s_int initialObjectId, s_int initialParentObjectId, TimelineKey *initialKey);

	private:
		ObjectRefInstance *getNewSpecializedObjectRefInstance(EntityInstance *entityInstance, EntityInstanceData *entityInstanceData, TransformProcessor *initialParentTransformer, UniversalObjectInterface *objectInstance) override;
	};
}

#endif // BONEREF_H
