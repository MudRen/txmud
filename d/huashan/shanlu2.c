// Room: /d/huashan/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��ɽ·���򱱾���ëŮ���ˣ�������ɽ���ס��˵���ëŮ
������ʮ��������̫ƽ����ȥ����û��һ���ܳ������������浽
����ЩʲôҲ������֪���ˡ�����һ��������ɽ֮���ջ�ţ�
ͨ��ɽ�ɵĲ�ʯ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"santai",
  "north" : __DIR__"maonv",
  "east":__DIR__"zhanqiao",
]));

	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
