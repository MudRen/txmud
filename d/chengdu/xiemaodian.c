// Room: /wiz/louth/c/xiemaodian.c

inherit ROOM;

void create()
{
	set("short", "Ьñ��");
	set("long", @LONG
�����ǳɶ��Ķ���Ь�ꡣ���ﶼ�е�����Ь�棬��ר�ŵ���
Ь�ڵĴ���ʵ��Ʒ��Ь�����ݷḻ��ͼ��ɫ�ʶ��������������
������Ͷ�Ҫ����������һ˫����Ь�档�����ǽ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jguanlu1",
]));
        set("objects",([
        __DIR__"npc/zhangboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
