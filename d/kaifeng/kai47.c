// Room: /u/w/wangs/b/kai47.c

inherit ROOM;

void create()
{
	set("short", "ɽ�Ͻ�");
	set("long", @LONG
��϶��ԣ�ɽ�Ͻֱȿ��⸮�������������խһ�㣬������
Ϊ��һ��ԭ����һƬƶ��ߣ�ֻ�ǵ�������꣬��������������
ʵ������Ÿĳɽֵ�������������Ѿ��Ҳ���һ�㵱��ƽ��ߵ�
Ӱ���ˣ���ʯ�̳ɵĴ����ֱ������Զ�������߶����۴��αȵ�
���̡����洫��һ������ѽѽ�ĳ�Ϸ����ԭ��������һ��ϷԺ��
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai50",
  "north" : __DIR__"kai43",
  "west" : __DIR__"kai48",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
