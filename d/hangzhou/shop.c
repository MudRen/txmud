// /d/hangzhou/shop.c

#include <room.h>

inherit ROOM;
string look_sign(object me);

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
�����Ǳ��ǵ�һ��С�ӻ��ꡣ�������˽���������������һ
Щ�ճ��õĶ�����
LONG
	);

	set("exits", ([
		"west"   : __DIR__"minan02",
	]) );


	set("objects", ([
		__DIR__"npc/boss_zahuo" : 1,
]) );


	setup();

}