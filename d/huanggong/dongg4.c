// Room: /d/huanggong/dongg4.c

inherit ROOM;

void create()
{
        set("short", "������԰");
        set("long", @LONG
�����Ƕ�����԰����ֲ�Ÿ����滨��ݣ���������������Ŀ��
ͬʱ��������ʱʱ���˶�����������˴����·��Ѻ���Ȼ��Ϊ
һ�壬ʹ����ȴ���еķ��ա���԰�л���һ������Ĵ����أ�
����ʱʱ�ɼ��������ʱ�����Ծ��ˮ�档�򶫻���һ��ͤ�ӡ�

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"dongg5",
  "west" : __DIR__"dongg3",
  "north" : __DIR__"dongg6",
]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}