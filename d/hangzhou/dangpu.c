// Room: /d/hangzhou/dangpu.c

inherit HOCKSHOP;

void create()
{
	set("short", "���ǵ���");
	set("long", @LONG
����һ����̣����ó��������ⲻ���󲿷ֹ˿Ͷ��Ǵ�
�ֶ���Ķĳ�������ĶĿͣ���һЩ��ù���̿ͣ�����һЩ����
�������˵�����ͼ۳���һЩ������Ʒ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"minan05",
]));

	set("objects",([
	__DIR__"npc/hockboss" : 1,
]));

	setup();
}
