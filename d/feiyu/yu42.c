// Room: /u/w/wangs/a/yu42.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������������ϣ���������ֲ�˴�Ƭ���ɰأ�
�����дУ����Ǿ��ף�����������������Ҷ��ɳɳ���⣬��
����ʲô�����������������������ͨ���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu41",
  "east" : __DIR__"yu43",
]));
        set("objects", ([
        __DIR__"npc/lixueling": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
