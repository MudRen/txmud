// Room: /d/feiyu/miaopu7.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[7]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"miaopu8",
  "north" : __DIR__"miaopu6",
]));

	set("outdoors","feiyu");
	setup();
}
