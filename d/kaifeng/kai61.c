// Room: /u/w/wangs/b/kai61.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ��������ӵ�ǽ�����ǽ֮���С�ֵ�������˵����
�ֻ�����˵��һ��С���խխ����������ȻҲû��ʲô̯����
����Ϊʲô��������ɽ���Ѿ��޴ӿ�֤�ˣ�������������������
��Ҳʮ�����֡������������ϴ�֣�·�ϱ���һ���鱦�ꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai49",
  "west" : __DIR__"kai58",
  "east" : __DIR__"sdoor",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
