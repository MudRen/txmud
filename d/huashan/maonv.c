// Room: /d/huashan/maonv.c

inherit ROOM;

void create()
{
	set("short", "ëŮ��");
	set("long", @LONG
�ഫս��ʱ��һλ�����������ϣ�����ҹ����Դ��ϣ���Ȼ
һ�������������������������Ӧ�����������ڻ�ɽ�ҵ��˴���
����ʹ�����ǽ�����Ϊ�������˳��׺������������ӡ����˾�
���˶�����ëŮ����
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wolf1" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"maonv1.c",
  "south" : __DIR__"shanlu2",
]));
	set("no_clean_up", 0);
	set("indoors", "huashan");

	setup();
	replace_program(ROOM);
}
