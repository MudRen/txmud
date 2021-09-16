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
        "unarmed":      "拳脚",
        "sword":        "剑法",
        "blade":        "刀法",
        "stick":        "棍法",
        "staff":        "杖法",
        "throwing":     "暗器",
	"iron-cloth": 	"硬功",
        "force":        "内功",
        "parry":        "招架",
        "dodge":        "轻功",
        "magic":        "法术",
        "spells":       "咒文",
        "move":         "行动",
        "array":        "阵法",
	"whip":     	"鞭法",
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
			return notify_fail( "你想查看谁的状态? \n" );

		my = player->query_entire_dbase();
		write(sprintf("先天属性:\n臂力(str): %d , 胆识(cor): %d , 悟性(int)：%d\n",
			my["str"],my["cor"],my["int"]));
		write(sprintf("根骨(con): %d , 福缘(kar): %d , 容貌(per)：%d\n",
			my["con"],my["kar"],my["per"]));
		write(sprintf("总点数：%d\n",my["str"]+my["cor"]+my["int"]+
			my["con"]+my["kar"]+my["per"]));

		write(money_status(player));

		map = player->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("他现在没有使用任何特殊技能。\n");

                skill = keys(valid_types);
                write("以下是他目前使用中的特殊技能。\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !player->query_skill(skill[i]) ) continue;
                        modify = player->query_temp("apply/" + skill[i]);
                        printf("  %-20s： %-20s  有效等级：%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "无" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                player->query_skill(skill[i]));
                }
                return 1;
        }

	else
	{
        	return notify_fail( "你想看谁的状态啊? \n" );
	}
}

private string money_status(object who)
{
	int g,s,c,i;
	mapping bank;
	string out;
	object *inv;

	if(!(bank = who->query("save_in_bank")))
		out = "\n银行没有存款。\n";
	else
	{
		g = bank["gold"];
		s = bank["silver"];
		c = bank["coin"];

		if(!g && !s && !c)
			out = "\n银行没有存款。\n";
		else
			out = sprintf("\n银行存有%s%s%s。\n",g?sprintf(" %d 黄金,",g):"",
				s?sprintf(" %d 白银,",s):"",c?sprintf(" %d 铜钱",c):"" );
	}

	inv = filter_array(deep_inventory(who),(: is_money :));
	if(!sizeof(inv))
		out += "身上没带钱。";
	else
	{
		out += "身上带有：\n";
		for(i=0;i<sizeof(inv);i++)
		{
			if(inv[i]->id("gold"))
				out += sprintf(" %d 黄金",inv[i]->query_amount());
			else if(inv[i]->id("silver"))
				out += sprintf(" %d 白银",inv[i]->query_amount());
			else if(inv[i]->id("coin"))
				out += sprintf(" %d 铜钱",inv[i]->query_amount());
			else if(inv[i]->id("thousand-cash"))
				out += sprintf(" %d 银票",inv[i]->query_amount());
		}
	}

	out += "\n\n";
	return out;
}


int help(object me)
{
  write(@HELP
指令格式 : checkout <ID>
 
此指令可检查玩家的先天属性总点数及
特殊武功的使用情况。

HELP
    );
    return 1;
}