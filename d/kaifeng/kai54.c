// Room: /u/w/wangs/b/kai54.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ��������ӵ�ǽ�����ǽ֮���С�ֵ�������˵����
�ֻ�����˵��һ��С���խխ����������ȻҲû��ʲô̯����
����Ϊʲô��������ɽ���Ѿ��޴ӿ�֤�ˣ�������������������
��Ҳʮ�����֡�������һ��С�Ĺݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai41",
  "west" : __DIR__"kai53",
  "east" : __DIR__"kai55",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
