// Room: /u/w/wangs/b/kai89.c

inherit ROOM;

void create()
{
	set("short", "���ⱱ��");
	set("long", @LONG
���ⱱ����һ������ϱ��Ĵ������Ϊ���������ž�ʡͨ��
��������Խ���ø��������·�ϳ�ˮ��������ҹ������������
�ͻ���ĳ��Ӵ�����ԴԴ���ϵķ�ɢ�����ҵ��̣��ִ��ſ����
����ӳ��и�����۵�������·�ϳ��Ƕ�ȥ��·�����ǿ����Ѳ
������������һ���䱸ɭ�ϵļ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai92",
  "south" : __DIR__"kai86",
  "west" : __DIR__"kai90",
  "east" : __DIR__"kai91",
]));

        set("objects",([
        NPC_DIR"xunpu" : 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
