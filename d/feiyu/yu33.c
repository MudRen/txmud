// Room: /u/w/wangs/a/yu33.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������е�һ�����ȣ�����������������Ҳ�ò���
�����˸���Ư����ͼ�Σ�������̾Ϊ��ֹ����ÿ�������ĵ�
������˵��һ��������������Ĺ��¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu34",
  "northeast" : __DIR__"yu32",
]));
        set("objects", ([
        __DIR__"npc/chengyuxin": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
