// Room: /u/w/wangs/b/kai86.c

inherit ROOM;

void create()
{
	set("short", "���ⱱ��");
	set("long", @LONG
���ⱱ����һ������ϱ��Ĵ������Ϊ���������ž�ʡͨ��
��������Խ���ø��������·�ϳ�ˮ��������ҹ������������
�ͻ���ĳ��Ӵ�����ԴԴ���ϵķ�ɢ�����ҵ��̣��ִ��ſ����
����ӳ��и�����۵�������·�ϳ��Ƕ�ȥ��·������һ����վ��
����������·��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai89",
  "south" : __DIR__"kai83",
  "west" : __DIR__"kai87",
  "east" : __DIR__"kai88",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 3,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
