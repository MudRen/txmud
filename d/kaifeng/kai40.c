// Room: /u/w/wangs/b/kai40.c

inherit ROOM;

void create()
{
	set("short", "ɽ�Ͻ�");
	set("long", @LONG
��϶��ԣ�ɽ�Ͻֱȿ��⸮�������������խһ�㣬������
Ϊ��һ��ԭ����һƬƶ��ߣ�ֻ�ǵ�������꣬��������������
ʵ������Ÿĳɽֵ�������������Ѿ��Ҳ���һ�㵱��ƽ��ߵ�
Ӱ���ˣ���ʯ�̳ɵĴ����ֱ������Զ�������߶����۴��αȵ�
���̡�������һ����֬�꣬��������Ů��������������֬�ۡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai43",
  "north" : __DIR__"kai37",
  "east" : __DIR__"kai42",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
