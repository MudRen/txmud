// Room: /u/w/wangs/a/yu95.c

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
  "southeast" : __DIR__"yu96",
  "northwest" : __DIR__"yu94",
]));
        set("objects", ([
        __DIR__"npc/zhaohongyue": 1,
                        ]) );

       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
