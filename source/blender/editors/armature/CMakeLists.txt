# ***** BEGIN GPL LICENSE BLOCK *****
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#
# Contributor(s): Jacques Beaurain.
#
# ***** END GPL LICENSE BLOCK *****

set(INC
	../include
	../../blenfont
	../../blenkernel
	../../blenlib
	../../blenloader
	../../makesdna
	../../makesrna
	../../windowmanager
	../../../../intern/guardedalloc
	../../../../intern/opennl/extern
)

set(INC_SYS
	${GLEW_INCLUDE_PATH}
)

set(SRC
	armature_ops.c
	editarmature.c
	editarmature_generate.c
	editarmature_retarget.c
	editarmature_sketch.c
	meshlaplacian.c
	poseSlide.c
	poseUtils.c
	poselib.c
	poseobject.c
	reeb.c

	BIF_generate.h
	BIF_retarget.h
	armature_intern.h
	meshlaplacian.h
	reeb.h
)

blender_add_lib(bf_editor_armature "${SRC}" "${INC}" "${INC_SYS}")
