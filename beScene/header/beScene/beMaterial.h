/****************************************************/
/* breeze Engine Scene Module  (c) Tobias Zirr 2011 */
/****************************************************/

#ifndef BE_SCENE_MATERIAL
#define BE_SCENE_MATERIAL

#include "beScene.h"
#include <beCore/beShared.h>
#include <beGraphics/beEffect.h>
#include <beGraphics/beEffectCache.h>
#include <beGraphics/beSetup.h>
#include <lean/tags/noncopyable.h>
#include <lean/smart/resource_ptr.h>
#include <vector>

namespace beScene
{

class MaterialCache;

/// Material class.
class Material : public lean::nonassignable, public beCore::Resource
{
public:
	struct Technique;
	typedef std::vector<Technique> technique_vector;

private:
	lean::resource_ptr<const beGraphics::Effect> m_pEffect;
	
	technique_vector m_techniques;

	MaterialCache *m_pCache;

public:
	/// Constructor.
	BE_SCENE_API Material(const beGraphics::Effect *pEffect, beGraphics::EffectCache &effectCache, MaterialCache *pCache = nullptr);
	/// Destructor.
	BE_SCENE_API virtual ~Material();

	/// Gets the number of techniques.
	BE_SCENE_API uint4 GetTechniqueCount() const;
	/// Gets the setup for the given technique.
	BE_SCENE_API beGraphics::Setup* GetSetup(uint4 techniqueIdx) const;
	/// Gets the technique identified by the given index.
	BE_SCENE_API const beGraphics::Technique* GetTechnique(uint4 techniqueIdx) const;
	/// Gets the name of the technique identified by the given index.
	BE_SCENE_API utf8_ntr GetTechniqueName(uint4 techniqueIdx) const;

	/// Gets the input signature of this pass.
	BE_SCENE_API const char* GetInputSignature(uint4 &size, uint4 techniqueIdx, uint4 passID = 0) const;

	/// Gets the effect.
	LEAN_INLINE const beGraphics::Effect* GetEffect() const { return m_pEffect; }
	/// Gets the material cache.
	LEAN_INLINE MaterialCache* GetCache() const { return m_pCache; }

};

} // namespace

#endif