// Room: /u/w/wangs/a/yu32.c

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
  "southwest" : __DIR__"yu33",
  "northeast" : __DIR__"yu31",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/songxiaoyun" : 1,
]));

	setup();
	replace_program(ROOM);
}
