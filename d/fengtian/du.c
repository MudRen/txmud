// Room: /d/fengtian/du.c

inherit DUCHANG;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
���������������÷�����Ȼ���ﵱ�ҵĺ����ſ�ջ���ϰ彻
���������ĵĻ������Ǹ���ȥ�����㿴�ſڵ��˽���������
������˸��ǻ���ڵأ��öĵ������������һ������ů�ĸо���
�ű߹���һ��ľ��(pai)д������ĶĹ档
LONG
);

	set("item_desc", ([
                "paizi" : "
���ĳ�Ŀǰ����Ѻ(bet)����С��,��������:
�������ӵ����ܺͣ�
       ��   �� ʮ   Ϊ��С��(small)��
       ʮһ �� ʮ�� Ϊ����(big)��
��Ҳ����Ѻȫɫ (all) ���������ӵ�����ͬ��
����Ѻ�Ľ��������ҡ���Ľ����ͬ����һ��һ��
����ѺȫɫѺ������һ��ˣ�Ѻ100��Ӯ800����\n
���ĳ�ֻ��������Ϊ��ע,���ٲ��ޡ�\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ll1",
]));

	set("objects",([
	__DIR__"npc/judge" : 1,
]));

	setup();
}