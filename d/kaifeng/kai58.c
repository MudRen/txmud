// Room: /wiz/louth/k/kai58.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ��������ӵ�ǽ�����ǽ֮���С�ֵ�������˵����
�ֻ�����˵��һ��С���խխ����������ȻҲû��ʲô̯����
����Ϊʲô��������ɽ���Ѿ��޴ӿ�֤�ˣ�������������������
��Ҳʮ�����֡�������һ����Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"kai61",
  "north" : __DIR__"kai8",
  "west" : __DIR__"kai55",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
