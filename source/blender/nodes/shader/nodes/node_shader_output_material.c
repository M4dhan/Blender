/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2005 Blender Foundation.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_output_material_in[]= {
	{	SOCK_SHADER, 1, "Surface"},
	{	SOCK_SHADER, 1, "Volume"},
	{	SOCK_FLOAT, 1, "Displacement",	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE, SOCK_HIDE_VALUE},
	{	-1, 0, ""	}
};

static int node_shader_gpu_output_material(GPUMaterial *mat, bNode *UNUSED(node), GPUNodeStack *in, GPUNodeStack *out)
{
	GPUNodeLink *outlink;

	GPU_stack_link(mat, "node_output_material", in, out, &outlink);
	GPU_material_output_link(mat, outlink);

	return 1;
}


/* node type definition */
void register_node_type_sh_output_material(bNodeTreeType *ttype)
{
	static bNodeType ntype;

	node_type_base(ttype, &ntype, SH_NODE_OUTPUT_MATERIAL, "Material Output", NODE_CLASS_OUTPUT, 0);
	node_type_compatibility(&ntype, NODE_NEW_SHADING);
	node_type_socket_templates(&ntype, sh_node_output_material_in, NULL);
	node_type_size(&ntype, 120, 60, 200);
	node_type_init(&ntype, NULL);
	node_type_storage(&ntype, "", NULL, NULL);
	node_type_exec(&ntype, NULL);
	node_type_gpu(&ntype, node_shader_gpu_output_material);

	/* Do not allow muting output node. */
	node_type_mute(&ntype, NULL, NULL);
	node_type_gpu_mute(&ntype, NULL);

	nodeRegisterType(ttype, &ntype);
}
