// Room: /d/huayin/miaopu4.c

inherit __DIR__"yao_tian";

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
������һ��Ƭ���ֵ���أ���ֵ�������û��һ˿ũ���ĺ�
������˵�����ǻ�ɽ��ר��������ֲ��ҩ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"miaopu9",
  "east" : __DIR__"miaopu5",
  "north" : __DIR__"miaopu3",
  "west" : __DIR__"shulin",
]));

	set("outdoors","huayin");
	setup();
}