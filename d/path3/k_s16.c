// Room: /d/path3/k_s16.c

inherit DANGER_ROAD;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ������С·��ÿ��һ�����ܴ����ٳ����������¿�
ȥ��ȴ�����˼������ɵ���ӿ��˽Ų���������һƬ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"k_s15",
  "south" : __DIR__"k_s17",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
