// Room: /u/w/wangs/a/yu97.c

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
  "southeast" : __DIR__"yu98",
  "west" : __DIR__"yu96",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/baitu" : 2,
]));

       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
