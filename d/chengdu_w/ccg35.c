// Room: /d/path5/ccg35.c

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
������ͨ���ɴ��򶫹���ɽ�����Ǵ�������ˣ�������Զ
��������һ�����䡣��������ãã�Ĳ�ԭ�����Ե�������·��һ
����һ������(pai)��
LONG
	);
	set("outdoors", "chengdu_w");
	set("exits", ([
  "west" : __DIR__"ccg36",
  "east" : __DIR__"ccg34",
  "north" : "/d/path6/lna01",
]));
	set("cannot_build_home", 1);
	set("item_desc", ([
	"pai" : "
	north        ����
	east         ŭ��
	west         ��֥ 
\n",
	"����" : "
	north        ����
	east         ŭ��
	west         ��֥ 
\n",
]));

	setup();
	replace_program(ROOM);
}
