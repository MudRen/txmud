// Room: /u/w/wangs/b/kai112.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǿ��������һ����֬�ꡣ�˴��·���Ӧ�о��еĸ�
����֬��ۣ�Ʒ���ر�ȫ������ǵĴ���Сϱ������������
���䣬Ҳ��һЩС���Ӿ�����������һЩ��֬����͸��İ�
�Ĺ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai106",
]));
        set("objects",([
        __DIR__"npc/fengboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
