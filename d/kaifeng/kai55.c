// Room: /u/w/wangs/b/kai55.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ��������ӵ�ǽ�����ǽ֮���С�ֵ�������˵����
�ֻ�����˵��һ��С���խխ����������ȻҲû��ʲô̯����
����Ϊʲô��������ɽ���Ѿ��޴ӿ�֤�ˣ�������������������
��Ҳʮ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kai54",
  "east" : __DIR__"kai58",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
