// Room: /u/w/wangs/a/yu98.c

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
  "southeast" : __DIR__"yu99",
  "northwest" : __DIR__"yu97",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
