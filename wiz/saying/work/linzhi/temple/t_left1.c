//t_left1.c ��ľ�����䳡��
inherit ROOM;
void create()
{
        set("short", "�㳡");
        set("long", @LONG
�����ǵ�ľ�µ����䳡���м����������ڶԴ򣬻��м�����
�������Ĺ��򣬾پ�ʯ�������ɳ��ʲô�ġ��㿴�˿����ƺ�û
��ʲô����Ĺ��򡣿������ڵĹ����ǲ������������洫��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"temple1",
]));
        set("objects",([
        __DIR__"obj/shisuo":2,
]));
        setup();
}
