// Room: /u/w/wangs/b/kai50.c

inherit ROOM;

void create()
{
	set("short", "ɽ�Ͻ�");
	set("long", @LONG
��϶��ԣ�ɽ�Ͻֱȿ��⸮�������������խһ�㣬������
Ϊ��һ��ԭ����һƬƶ��ߣ�ֻ�ǵ�������꣬��������������
ʵ������Ÿĳɽֵ�������������Ѿ��Ҳ���һ�㵱��ƽ��ߵ�
Ӱ���ˣ���ʯ�̳ɵĴ����ֱ������Զ�������߶����۴��αȵ�
���̡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"kai53",
  "north" : __DIR__"kai47",
  "west" : __DIR__"kai51",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
