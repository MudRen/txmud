// Room: /d/feiyu/miaopu1.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[1]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"miaopu2",
  "south" : __DIR__"miaopu6",
]));

	set("outdoors","feiyu");
	setup();
}
