// Room: /u/w/wangs/b/kai92.c

inherit ROOM;

void create()
{
	set("short", "���ⱱ��");
	set("long", @LONG
���ⱱ����һ������ϱ��Ĵ������Ϊ���������ž�ʡͨ��
��������Խ���ø��������·�ϳ�ˮ��������ҹ������������
�ͻ���ĳ��Ӵ�����ԴԴ���ϵķ�ɢ�����ҵ��̣��ִ��ſ����
����ӳ��и�����۵�������·�ϳ��Ƕ�ȥ��·�����ǳ���·��
�����Ǳ�Ӫ�����������ǿ��ⱱ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ndoor",
  "south" : __DIR__"kai89",
  "west" : __DIR__"kai32",
  "east" : __DIR__"kai93",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
