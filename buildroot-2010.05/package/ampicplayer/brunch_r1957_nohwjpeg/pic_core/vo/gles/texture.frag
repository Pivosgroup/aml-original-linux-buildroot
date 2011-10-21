/* vim:set sts=4 ts=4 noexpandtab cindent syntax=c: */
/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2009 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

#version 100

precision mediump float;

uniform sampler2D u_s2dTexture;

varying vec2 v_v2TexCoord;

void main()
{
	gl_FragColor = texture2D(u_s2dTexture, v_v2TexCoord);
}

