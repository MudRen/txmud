// Room: /u/w/wangs/b/kai146.c

inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
������һ���ٽֶ����ı�Ӫ�����뿪��Ķ�����ֻ�м���֮
ң����Ӫ�ſ����Ʈ�ż�����Կ�����ʿ�������ڣ����Ҳ���
��ɫ��Ѱ�������ܡ���Ӫ���浽�����йٱ������ػص��߶�����
һ���佫����ָ��ʿ���жӲ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai144",
]));

        set("objects",([
        __DIR__"npc/guanbing" : 4,
]));

	setup();
	replace_program(ROOM);
}
