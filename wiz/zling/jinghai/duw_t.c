// Room: /d/jinghai/duw_t.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
        set("short", "�ɴ�");
        set("long", @LONG
����һ����С�Ķɴ���ľͷ�ṹ�����������������˵�����
��վ������ңң�λΣ����˸о��ܲ���ʵ��
LONG
        );
        set(SAFE_ENV,1);
        set("no_clean_up",1);
        set("invalid_fuji", 1);

        set_boat_master(__DIR__"npc/chuanjia");
        set_boat_bank1(__DIR__"th01");
        set_boat_bank2(__DIR__"wm1");
        set_bank1_desc("�һ���");
        set_bank2_desc("������");
        set_cross_msg("�ɺ�");

        setup();
}
