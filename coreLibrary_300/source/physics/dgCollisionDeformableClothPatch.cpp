/* Copyright (c) <2003-2016> <Julio Jerez, Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 
* 3. This notice may not be removed or altered from any source distribution.
*/

#include "dgPhysicsStdafx.h"


#include "dgBody.h"
#include "dgWorld.h"
#include "dgContact.h"
#include "dgMeshEffect.h"
#include "dgCollisionBVH.h"
#include "dgCollisionConvexPolygon.h"
#include "dgCollisionDeformableClothPatch.h"


dgCollisionDeformableClothPatch::dgCollisionDeformableClothPatch(dgWorld* const world, dgMeshEffect* const mesh)
	:dgCollisionDeformableMesh(world, mesh, m_deformableSolidMesh)
{
	m_rtti |= dgCollisionDeformableClothPatch_RTTI;
}


dgCollisionDeformableClothPatch::dgCollisionDeformableClothPatch(const dgCollisionDeformableClothPatch& source)
	:dgCollisionDeformableMesh(source)
{
	m_rtti |= source.m_rtti;

}

dgCollisionDeformableClothPatch::dgCollisionDeformableClothPatch(dgWorld* const world, dgDeserialize deserialization, void* const userData, dgInt32 revisionNumber)
	:dgCollisionDeformableMesh(world, deserialization, userData, revisionNumber)
{
}

dgCollisionDeformableClothPatch::~dgCollisionDeformableClothPatch(void)
{
}


