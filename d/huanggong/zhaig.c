// Room: /d/huanggong/zhaig.c

inherit ROOM;

void create()
{
	set("short", "ի��");
	set("long", @LONG
�����ǻ���ÿ��������桢����������ǰ��Ϊ�������챣��
������ի���ĵط�����޴�ķ�̨�������ŷ�������Ħ��ķ�
�񡣴������ɵ���¯��ð�����������̣�������Ƣ����ö������
��Ӥ�����ֱۣ�����������յĵƻ�ͨ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huangjd",
  "north" : __DIR__"xigdm",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}