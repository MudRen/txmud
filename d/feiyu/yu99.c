// Room: /u/w/wangs/a/yu99.c

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
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"yu98",
  "east" : __DIR__"yu50",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
