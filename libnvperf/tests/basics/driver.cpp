// Load the host library at runtime through nvperf_host_impl.h, as
// NvPerfUtility expects.
//
#include <nvperf_host_impl.h>

#include <NvPerfInit.h>
#include <NvPerfCounterConfiguration.h>
#include <NvPerfMetricsEvaluator.h>

#undef NDEBUG
#include <cassert>

int main ()
{
  NVPW_InitializeHost_Params p {};
  p.structSize = NVPW_InitializeHost_Params_STRUCT_SIZE;

  // The host library is only loaded if it is in the library search path.
  //
  NVPA_Status s (NVPW_InitializeHost (&p));
  assert (s == NVPA_STATUS_SUCCESS || s == NVPA_STATUS_NOT_LOADED);
}
