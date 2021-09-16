// parry.c

inherit SKILL;

string *parry_msg = ({
	"只听见「锵」的一声，被$p用$v格开了。\n",
	"结果「当」地一声被$p用$v挡开了。\n",
	"但是被$n用手中的$v架开。\n",
	"但是$n身子一侧，用手中的$v格开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
	"但是被$p格开了。\n",
	"结果被$p挡开了。\n",
});

string query_parry_msg(object weapon,object weapon_v)
{
	if( weapon && weapon_v )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
