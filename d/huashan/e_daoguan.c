// Room: /d/huashan/e_daoguan.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ƕ���Ժ����������������ڴ���������ɽ���̵ĺ�
�����Ӷ��ڴ���ϰ��ѧ���������Ե�֣�����������ϼ�������
�ĵõ����ϡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huixin",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
