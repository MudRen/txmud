// Room: /wiz/louth/c/guangbaosi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����λ�ڳɶ��б��¶����ڵı����¡������ҹ��Ϸ��Ĵ��
��֮һ��ʼ���ڶ���������ս�𣬼������ޣ��ճɽ���֮��ģ��
ȫ�µ������ģ���ľ���ף����ʮ��Ժ���ݽ������۱����
���޺�������������Լ���׵Ĳʻ������޺���������������
������죬������ͬ������������Ʒ��������ʮ��·�ڡ�
LONG
);

	set(SAFE_ENV, 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shizi",
]));
        set("objects",([
        __DIR__"npc/bonze" : 1,
]));

	setup();
	replace_program(ROOM);
}
