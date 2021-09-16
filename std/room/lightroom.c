// /std/room/lightroom.c
// by Find.

#include <ansi.h>
inherit ROOM;

static int dark_level = 1;

int is_lightroom() { return 1; }
int query_dark_level() { return dark_level; }

void add_dark_level(int i)
{
	int old;

	if(!intp(i) || !i)
		return;

	old = dark_level;
	dark_level += i;

	if( i < 0 )
	{
		if( (old > 0) && (dark_level <= 0) )
			tell_room(this_object(),"只见一道亮光，你眼前的景物清晰的浮现出来。\n",
				this_player()?({this_player()}):0);
	}

	else
	{
		if( (old <= 0) && (dark_level > 0) )
			tell_room(this_object(),WHT+"你眼前一黑，什么也看不见了。\n"+NOR,
				this_player()?({this_player()}):0);
	}
}

void char_comeon_room(object me)
{
	object *objs;

	if(!objectp(me) || !me->is_character())
		return;

	objs = all_inventory(this_player());
	for(int i=0;i<sizeof(objs);i++)
		if(objs[i]->is_light_ob() && objs[i]->is_lighting() == 1)
			add_dark_level(-1);
}

void char_leave_room(object me)
{
	object *objs;

	if(!objectp(me) || !me->is_character())
		return;

	objs = all_inventory(me);
	for(int i=0; i<sizeof(objs); i++)
	{
		if(objs[i]->is_light_ob() && objs[i]->is_lighting() == 1)
			add_dark_level(1);
	}
	return;
}
