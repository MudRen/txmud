// Room: /u/w/wangs/a/yu94.c

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
  "southeast" : __DIR__"yu95",
  "northwest" : __DIR__"yu93",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
