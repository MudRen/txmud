// Room: /u/w/wangs/b/kai75.c

inherit ROOM;

void create()
{
	set("short", "���Ľ�");
	set("long", @LONG
���Ľ��ǿ��⸮����ĵ��򣬽ֵ�һ�����������Ĺ㳡��
��һ�������������ӿ�볱�����ǵ�����䣬��������������
������磬����С�ԡ�̯����������ڴˣ�ʵΪ����һ���쾰��
���Ե������ְ��������Ľֽ��������Χ������
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai77",
  "south" : __DIR__"kai74",
  "west" : __DIR__"kai72",
  "east" : __DIR__"kai76",
]));

	set("outdoors","kaifeng");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
