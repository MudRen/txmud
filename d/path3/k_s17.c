// Room: /d/path3/k_s17.c

inherit DANGER_ROAD;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ������С·��ÿ��һ�����ܴ����ٳ����������¿�
ȥ��ȴ�����˼������ɵ���ӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s18",
  "north" : __DIR__"k_s16",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
