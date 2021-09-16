//
// checkout.c
//
// Created :  96-08-15  09:20PM   Falcon
//
// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;
private string money_status(object who);
mapping valid_types = ([
        "unarmed":      "ȭ��",
        "sword":        "����",
        "blade":        "����",
        "stick":        "����",
        "staff":        "�ȷ�",
        "throwing":     "����",
	"iron-cloth": 	"Ӳ��",
        "force":        "�ڹ�",
        "parry":        "�м�",
        "dodge":        "�Ṧ",
        "magic":        "����",
        "spells":       "����",
        "move":         "�ж�",
        "array":        "��",
	"whip":     	"�޷�",
]);

int main(object me, string arg)
{
	object player;
        mapping map,my;
        string *skill;
        int i, modify;

        if ( arg )
	{
         	player = present( arg, environment( me ) );
		if ( !player )
			player = find_player( arg );
		if ( !player )
			player = find_living( arg );
		if ( !player )
			return notify_fail( "����鿴˭��״̬? \n" );

		my = player->query_entire_dbase();
		write(sprintf("��������:\n����(str): %d , ��ʶ(cor): %d , ����(int)��%d\n",
			my["str"],my["cor"],my["int"]));
		write(sprintf("����(con): %d , ��Ե(kar): %d , ��ò(per)��%d\n",
			my["con"],my["kar"],my["per"]));
		write(sprintf("�ܵ�����%d\n",my["str"]+my["cor"]+my["int"]+
			my["con"]+my["kar"]+my["per"]));

		write(money_status(player));

		map = player->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");

                skill = keys(valid_types);
                write("��������Ŀǰʹ���е����⼼�ܡ�\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !player->query_skill(skill[i]) ) continue;
                        modify = player->query_temp("apply/" + skill[i]);
                        printf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "��" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                player->query_skill(skill[i]));
                }
                return 1;
        }

	else
	{
        	return notify_fail( "���뿴˭��״̬��? \n" );
	}
}

private string money_status(object who)
{
	int g,s,c,i;
	mapping bank;
	string out;
	object *inv;

	if(!(bank = who->query("save_in_bank")))
		out = "\n����û�д�\n";
	else
	{
		g = bank["gold"];
		s = bank["silver"];
		c = bank["coin"];

		if(!g && !s && !c)
			out = "\n����û�д�\n";
		else
			out = sprintf("\n���д���%s%s%s��\n",g?sprintf(" %d �ƽ�,",g):"",
				s?sprintf(" %d ����,",s):"",c?sprintf(" %d ͭǮ",c):"" );
	}

	inv = filter_array(deep_inventory(who),(: is_money :));
	if(!sizeof(inv))
		out += "����û��Ǯ��";
	else
	{
		out += "���ϴ��У�\n";
		for(i=0;i<sizeof(inv);i++)
		{
			if(inv[i]->id("gold"))
				out += sprintf(" %d �ƽ�",inv[i]->query_amount());
			else if(inv[i]->id("silver"))
				out += sprintf(" %d ����",inv[i]->query_amount());
			else if(inv[i]->id("coin"))
				out += sprintf(" %d ͭǮ",inv[i]->query_amount());
			else if(inv[i]->id("thousand-cash"))
				out += sprintf(" %d ��Ʊ",inv[i]->query_amount());
		}
	}

	out += "\n\n";
	return out;
}


int help(object me)
{
  write(@HELP
ָ���ʽ : checkout <ID>
 
��ָ��ɼ����ҵ����������ܵ�����
�����书��ʹ�������

HELP
    );
    return 1;
}