// Room: /d/path3/k_s19.c

inherit DANGER_ROAD;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��ÿ��һ�����ܴ����ٳ����������¿�
ȥ��ȴ�����˼������ɵ���ӿ��˽Ų����ϱ߲�ʱ�������ϵ�ˮ
����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s20",
  "north" : __DIR__"k_s18",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
