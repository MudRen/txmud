// Room: /u/w/wangs/a/yu96.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
���������е�һ���Ӳݴ�������С·��������ƽʱû
ʲô�˼���·�߿��Ų�֪����Ұ�������ߵ�������Ȼ�ߴ�
ͦ�Ρ�����͸�����յ��������ǰ߲߰�����Ӱ�ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yu95",
  "east" : __DIR__"yu97",
  "south" : __DIR__"miaopu2",
]));
	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
